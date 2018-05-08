clear
clc


global xmlFrameworkName;

Build_Cfg();
tapas_types('load');
app_types('load');

status = {};
Generation_OK = 1;

% cd app_AccelMgr
% status_app_AccelMgr = tapas('app_AccelMgr');
% status = [status; {'app_AccelMgr', status_app_AccelMgr}];
% cd ..
% 
% cd app_AirConMgr
% status_app_AirConMgr = tapas('app_AirConMgr');
% status = [status; {'app_AirConMgr', status_app_AirConMgr}];
% cd ..
% 
% cd app_BatteryMgr
% status_app_BatteryMgr = tapas('app_BatteryMgr');
% status = [status; {'app_BatteryMgr', status_app_BatteryMgr}];
% cd ..
% 
% cd app_BrakeMgr
% status_app_BrakeMgr = tapas('app_BrakeMgr');
% status = [status; {'app_BrakeMgr', status_app_BrakeMgr}];
% cd ..
% cd app_ChargingMgr
% status_app_ChargingMgr = tapas('app_ChargingMgr');
% status = [status; {'app_ChargingMgr', status_app_ChargingMgr}];
% cd ..
% 
% cd app_ComMgr
% status_app_ComMgr = tapas('app_ComMgr');
% status = [status; {'app_ComMgr', status_app_ComMgr}];
% cd ..
% 
% cd app_CoolingMgr
% status_app_CoolingMgr = tapas('app_CoolingMgr');
% status = [status; {'app_CoolingMgr', status_app_CoolingMgr}];
% cd ..
% 
% cd app_DashMgr
% status_app_DashMgr = tapas('app_DashMgr');
% status = [status; {'app_DashMgr', status_app_DashMgr}];
% cd ..
% 
% cd app_DcDcMgr
% status_app_DcDcMgr = tapas('app_DcDcMgr');
% status = [status; {'app_DcDcMgr', status_app_DcDcMgr}];
% cd ..
% 
cd app_DrivingMgr
status_app_DrivingMgr = tapas('app_DrivingMgr');
status = [status; {'app_DrivingMgr', status_app_DrivingMgr}];
cd ..
% 
% cd app_GearMgr
% status_app_GearMgr = tapas('app_GearMgr');
% status = [status; {'app_GearMgr', status_app_GearMgr}];
% cd ..
% 
% cd app_LightMgr
% status_app_LightMgr = tapas('app_LightMgr');
% status = [status; {'app_LightMgr', status_app_LightMgr}];
% cd ..
% 
% cd app_McuMgr
% status_app_McuMgr = tapas('app_McuMgr');
% status = [status; {'app_McuMgr', status_app_McuMgr}];
% cd ..
% 
% cd app_PowerSteeringMgr
% status_app_PowerSteeringMgr = tapas('app_PowerSteeringMgr');
% status = [status; {'app_PowerSteeringMgr', status_app_PowerSteeringMgr}];
% cd ..
% 
% cd app_StartKeyMgr
% status_app_StartKeyMgr = tapas('app_StartKeyMgr');
% status = [status; {'app_StartKeyMgr', status_app_StartKeyMgr}];
% cd ..
% 
% cd app_SysMgr
% status_app_SysMgr = tapas('app_SysMgr');
% status = [status; {'app_SysMgr', status_app_SysMgr}];
% cd ..
% 
% cd app_AutoMgr
% status_app_AutoMgr = tapas('app_AutoMgr');
% status = [status; {'app_AutoMgr', status_app_AutoMgr}];
% cd ..
% 
% cd app_PosMgr
% status_app_PosMgr = tapas('app_PosMgr');
% status = [status; {'app_PosMgr', status_app_PosMgr}];
% cd ..
%
% cd app_test_gen
% status_app_test_gen = tapas('app_test_gen');
% status = [status; {'app_test_gen', status_app_test_gen}];
% 
% cd ..

status_rte = tapas_rte(xmlFrameworkName);
status = [status; {'RTE LAYER', status_rte}];

clc

disp('Generation Report')

[r,c] = size(status);
for i=1:r
    if(strcmp(status{i,2},'STATUS_OK')==1)
        disp([status{i,1} ' ' status{i,2}])
    else
        Generation_OK = 0;
        fprintf(2,[status{i,1} ' ' status{i,2} '\n']);
    end
end
disp('Generation Report End')


if(Generation_OK == 1)
    Build
else
    fprintf(2,['Code Gerneation was not OK ...' '\n']);
end