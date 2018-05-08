function Build_Cfg()

global BuildDestination
global xmlFrameworkName;
global OutputName;

BuildDestination = 'C:\Builds\DE_ECU';
xmlFrameworkName = 'de_ecu.fwxml';
OutputName = 'DE_ECU';

addpath(genpath('..\..\..\'))
try
	mkdir(BuildDestination)
end

end

