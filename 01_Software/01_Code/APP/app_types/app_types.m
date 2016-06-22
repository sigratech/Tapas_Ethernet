function app_types(command)


  aAppEnumAvailable = {};
  % Enums

  Simulink.defineIntEnumType('System_States_t', ... 
  {'SYS_STATE_IDLE','SYS_STATE_NEUTRAL','SYS_STATE_DRIVING','SYS_STATE_REVERSING', 'SYS_STATE_FAULT','SYS_STATE_DIAG'}, ... 
  [1;2;3;4;255;254],...
  'Description', 'enum for System States', ...
  'DefaultValue', 'SYS_STATE_IDLE', ...
  'AddClassNameToEnumNames', true);

  aAppEnumAvailable = [aAppEnumAvailable; 'System_States_t'];

  disp('APP Types Loaded ...');
  
  %% Display
  if(strcmp(command,'display'))
    disp('APP Types Available:');
    for index=1:length(aAppEnumAvailable)
      disp(aAppEnumAvailable{index});
    end
  end
end