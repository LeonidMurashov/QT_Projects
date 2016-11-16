; ������� ������������ ������ �������� Inno Setup.
; �������� � ������������ �������� � �������� ������ �������� INNO SETUP!

[Setup]
; ����������: �������� AppId ��������� �������������� ����������.
; �� ����������� �� �� �������� AppId � ������������ ��� ������ ����������.
; (����� ������� ����� ������������� GUID, ������� ������ | ������������ GUID � ��������������� ����� ����������).
AppId={{A34F1E8B-B83C-4011-8E4E-BE19156D3693}
AppName=PE_Calc
AppVersion=v1.1
;AppVerName=PE_Calc v1.0alfa
AppPublisher=LeoMur
DefaultDirName={pf}\LeoMur\PE_Calc
DefaultGroupName=LeoMur
LicenseFile=D:\QT_projects\���.txt
InfoBeforeFile=D:\QT_projects\�����.txt
OutputDir=D:\QT_projects
OutputBaseFilename=PE_Calc_Installer
SetupIconFile=D:\PE2\PE_Calc_Installer.ico
UninstallDisplayIcon=D:\PE2\PE_Calc_Uninstaller.ico 
Compression=lzma
SolidCompression=yes

[Languages]
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\PE_Calc.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\icudt54.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\icuin54.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\icuuc54.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\libgcc_s_dw2-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\libstdc++-6.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\libwinpthread-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\listwsort.o"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\main.o"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\mainmenu.o"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\mainwindow.o"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\qcustomplot.o"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\qrc_resource.cpp"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\qrc_resource.o"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\Qt5Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\Qt5Gui.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\Qt5PrintSupport.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\Qt5Widgets.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\unit.o"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\Data\*"; DestDir: "{app}\Data"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\build-PE-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\platforms\*"; DestDir: "{app}\platforms"; Flags: ignoreversion recursesubdirs createallsubdirs
; ����������: �� ����������� "Flags: ignoreversion" ��� ����� ����� ��������� ������

[Icons]
Name: "{group}\PE_Calc"; Filename: "{app}\PE_Calc.exe"
;Name: "{group}\{cm:UninstallProgram,PE_Calc}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\PE_Calc"; Filename: "{app}\PE_Calc.exe"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\PE_Calc"; Filename: "{app}\PE_Calc.exe"; Tasks: quicklaunchicon


[Run]
Filename: "{app}\PE_Calc.exe"; Description: "{cm:LaunchProgram,PE_Calc}"; Flags: nowait postinstall skipifsilent

[Registry]
Root: HKCU; Subkey: "Software\LeoMur"; Flags: uninsdeletekey