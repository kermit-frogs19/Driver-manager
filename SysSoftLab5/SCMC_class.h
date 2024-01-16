#define FILE_DEVICE_IOCTL  0x00008301

#define IOCTL_MY_NEITHER   CTL_CODE(FILE_DEVICE_IOCTL, 0x800, METHOD_NEITHER, FILE_ANY_ACCESS)
#define IOCTL_MY_BUFFERED  CTL_CODE(FILE_DEVICE_IOCTL, 0x801, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_MY_INDIRECT  CTL_CODE(FILE_DEVICE_IOCTL, 0x802, METHOD_IN_DIRECT, FILE_ANY_ACCESS)
#define IOCTL_MY_OUTDIRECT CTL_CODE(FILE_DEVICE_IOCTL, 0x803, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)

#define IOCTL_UNK_NEITHER   CTL_CODE(FILE_DEVICE_IOCTL, 0x804, METHOD_NEITHER,  FILE_ANY_ACCESS)
#define IOCTL_UNK_BUFFERED  CTL_CODE(FILE_DEVICE_IOCTL, 0x805, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_UNK_INDIRECT  CTL_CODE(FILE_DEVICE_IOCTL, 0x806, METHOD_IN_DIRECT, FILE_ANY_ACCESS)
#define IOCTL_UNK_OUTDIRECT CTL_CODE(FILE_DEVICE_IOCTL, 0x807, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)

class ServiceControlManagerControl
{
private:
	SC_HANDLE schSCManager;
	HANDLE Device;
	WCHAR DisplayName[100];
	WCHAR BinaryPathName[MAX_PATH];
public:
	ServiceControlManagerControl()
	{
		schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	}
	~ServiceControlManagerControl()
	{

	}
	void SetDriverInfo(LPCWSTR DisplayName, LPCWSTR BinaryPathName)
	{
		wcsncpy(this->DisplayName, DisplayName, 100);
		wcsncpy(this->BinaryPathName, BinaryPathName, MAX_PATH);
	}

	DWORD Add()
	{
		SC_HANDLE  schService;

		schService = CreateService(
			schSCManager,          
			DisplayName,           
			DisplayName,           
			SERVICE_ALL_ACCESS,    
			SERVICE_KERNEL_DRIVER, 
			SERVICE_DEMAND_START,  
			SERVICE_ERROR_NORMAL,  
			BinaryPathName,            
			NULL,                  
			NULL,                  
			NULL,                  
			NULL,                  
			NULL                   
		);
		if (schService == NULL)
		{
			return GetLastError();
		}
		CloseServiceHandle(schService);
		return ERROR_SUCCESS;
	}

	DWORD Remove()
	{
		SC_HANDLE  schService;
		schService = OpenService(schSCManager,DisplayName, SERVICE_ALL_ACCESS);
		if (schService == NULL)
		{
			return GetLastError();
		}
		if (DeleteService(schService))
		{			
			CloseServiceHandle(schService);
			return ERROR_SUCCESS;
		}
		CloseServiceHandle(schService);
		return GetLastError();
	}

	DWORD Start()
	{
		SC_HANDLE  schService;
		schService = OpenService(schSCManager, DisplayName,	SERVICE_ALL_ACCESS);
		if (schService == NULL)
		{
			return GetLastError();
		}
		BOOL start = StartService(schService, 0, NULL);
		CloseServiceHandle(schService);
		if (start)
		{
			return ERROR_SUCCESS;
		}
		return GetLastError();
	}

	DWORD Stop()
	{
		SC_HANDLE schService;
		SERVICE_STATUS ServiceStatus;
		schService = OpenService(schSCManager, DisplayName,	SERVICE_ALL_ACCESS);
		if (schService == NULL)
		{
			return GetLastError();
		}
		BOOL control = ControlService(schService, SERVICE_CONTROL_STOP,	&ServiceStatus);
		CloseServiceHandle(schService);
		if (control)
		{
			return ERROR_SUCCESS;
		}
		return GetLastError();
	}

	DWORD Open(LPCWSTR SymbolicLinkName)
	{
		WCHAR DeviceName[64] = L"\\\\.\\";
		HANDLE hDevice;
		if (this->Device != NULL)
		{
			return -1;
		}
		wcsncat(DeviceName, SymbolicLinkName, 100);

		hDevice = CreateFile(
			(LPCWSTR)DeviceName,
			GENERIC_READ | GENERIC_WRITE,
			0,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL
		);

		if (hDevice != ((HANDLE)-1))
		{
			this->Device = hDevice;
			return -3;
		}
		return -2;
	}

	DWORD Close()
	{
		if (this->Device == NULL)
		{
			return ERROR_DEVICE_NOT_CONNECTED;
		}
		CloseHandle(Device);
		Device = NULL;
		return ERROR_SUCCESS;
	}

	DWORD Read(std::wstring* text, unsigned char* buf, DWORD bsize)
	{
		if (Device == NULL)
		{
			return ERROR_DEVICE_NOT_CONNECTED;
		}
		if (!ReadFile(Device, buf, 8, &bsize, NULL))
		{
			return GetLastError();
		}
		*text += std::to_wstring(bsize);
		*text += L" bytes read successfully\n";
		*text += L"first four bytes read: ";
		*text += wchar_t(buf[0]);
		*text += wchar_t(buf[1]);
		*text += wchar_t(buf[2]);
		*text += wchar_t(buf[3]);
		*text += L'\n';
		return ERROR_SUCCESS;
	}

	DWORD Write(std::wstring* text, unsigned char* buf, DWORD bsize)
	{
		if (Device == NULL)
		{
			return ERROR_DEVICE_NOT_CONNECTED;
		}
		if (!WriteFile(Device, buf, 16, &bsize, NULL))
		{
			return GetLastError();
		}
		*text += std::to_wstring(bsize);
		*text += L" bytes written successfully\n";
		return ERROR_SUCCESS;
	}

	DWORD SendCtlCode(std::wstring* text, DWORD CtlCode, unsigned char* InBuf, DWORD InBufSize, unsigned char* OutBuf, DWORD OutBufSize)
	{
		if (Device == NULL)
		{
			return ERROR_DEVICE_NOT_CONNECTED;
		}
		if (!DeviceIoControl(Device, CtlCode, InBuf, 8, OutBuf, 16, &OutBufSize, NULL))
		{
			return GetLastError();
		}
		*text += std::to_wstring(OutBufSize);
		*text += L" bytes read/write successfully\n";
		*text += L"first four bytes read: ";
		*text += wchar_t(OutBuf[0]);
		*text += wchar_t(OutBuf[1]);
		*text += wchar_t(OutBuf[2]);
		*text += wchar_t(OutBuf[3]);
		*text += L'\n';
		return ERROR_SUCCESS;
	}
};