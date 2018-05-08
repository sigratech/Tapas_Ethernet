clear
clc

global BuildDestination;
global OutputName;

Build_Cfg();

disp('Building Executable ...');
[status, results] = dos(['iarbuild ..\..\' OutputName '.ewp -build "Flash Debug"'], '-echo');
if(status==0)
    errorCountCharDigit1 = results(end-29);
    if(errorCountCharDigit1 == '0')
        disp('Building executable was successful ...');
        try
            rmdir('Build','s');
        catch e
            % Do Nothing
        end

        clkid = clock();
        year = num2str(clkid(1));
        month = clkid(2);
        if(month < 10)
            month = ['0' num2str(month)];
        else
            month = num2str(month);
        end
        day = clkid(3);
        if(day < 10)
            day = ['0' num2str(day)];
        else
            day = num2str(day);
        end
        hour = clkid(4);
        if(hour < 10)
            hour = ['0' num2str(hour)];
        else
            hour = num2str(hour);
        end
        minute = clkid(5);
        if(minute < 10)
            minute = ['0' num2str(minute)];
        else
            minute = num2str(minute);
        end
        BuildName = ['Build' '_' year '_' month '_' day '_' hour '_' minute];
        mkdir(BuildName);
        copyfile(['..\..\Flash_Debug\Exe\' OutputName '.srec'],[BuildName '\' OutputName '.srec']);
        copyfile(['..\..\Flash_Debug\Exe\' OutputName '.out'],[BuildName '\' OutputName '.out']);
        copyfile(['..\..\Flash_Debug\List\' OutputName '.map'],[BuildName '\' OutputName '.map']);
        copyfile('..\..\01_Code\RTE\rte.h',[BuildName '\rte.h']);
        movefile(BuildName, BuildDestination);
        disp(['Build Name: ' BuildName]);
        disp(['Build Location: ' BuildDestination BuildName]);
    else
        fprintf(2,['Building executable was not successful ...' '\n']);
    end
else
    fprintf(2,['Building executable commmand line command was not successful ...' '\n']);
end