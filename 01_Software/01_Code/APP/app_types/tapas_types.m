function tapas_types(command)

  aEnumAvailable ={};

  aEnumAvailable = [aEnumAvailable; tapas_types_dbc()];

  switch(command)
    case 'display'
      disp('TAPAS Types Available: ');
      disp('--------------------- ');
      for index=1:length(aEnumAvailable)
        disp(aEnumAvailable{index});
      end
    case 'load'
      disp('TAPAS Types loaded ...')
    otherwise
      error(['TAPAS ERROR: ' command ' command is not supported, only display and load are supported']);
  end
end


