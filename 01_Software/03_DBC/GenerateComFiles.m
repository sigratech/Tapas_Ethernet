clear
clc
disp('Starting ...')

%% Configurations 
CFG_DBC_PATH = 'DE_ECU.dbc';

CFG_ACELL_RX_FRAME_HEX_IDS = {'C00D0EF','180000D0','738','700','739','73C','73F','742','745','748','74B','74E','751','754','757','75A','75D','760','763'};
CFG_ACELL_TX_FRAME_HEX_IDS = {'80','7AA','7AB','1800D000'};

CFG_ACELL_CAN_NETWORK_NAMES = {'CAN1_250Kb', 'CAN2_250Kb', 'CAN3_500Kb'};

CFG_STR_DIAG_TX_HEX_ID = '301'; %'3A3';
CFG_STR_DIAG_RX_HEX_ID = '300'; '3A2';
CFG_NUM_XCP_CAN_CHANNEL_ID = 1;
CFG_STR_XCP_RESPONSE_TX_HEX_ID = '1A2';
CFG_STR_XCP_HEARTBEAT_TX_HEX_ID = '1A3';
CFG_STR_XCP_REQUEST_RX_HEX_ID = '2A2';
CFG_STR_XCP_HEARTBEAT_RX_HEX_ID = '2A3';

CFG_FLAG_GEN_LIB = true;
CFG_STR_OUTPUT_COM_LIB_NAME = 'Lib_DeEcu_Com';
CFG_FLAG_SHOW_GEN_LIB = false;

CFG_FLAG_MOVE_FILE_TO_PROJECT = true;
CFG_STR_PATH_TAPAS_CFG = 'DE_ECU';

CFG_FLAG_SAVE_LOGS_TO_WORKSPACE = false;
CFG_CLEAR_OUTPUT = true;

CFG_SIGNED_SIGNALS_SUPPORTED = true;

CFG_CAN_TASK_MS = 10;

%% Generation
Status = tapas_dbc(CFG_DBC_PATH,...
                   CFG_ACELL_RX_FRAME_HEX_IDS,...
                   CFG_ACELL_TX_FRAME_HEX_IDS,...
                   CFG_ACELL_CAN_NETWORK_NAMES,...
                   CFG_STR_DIAG_TX_HEX_ID,...
                   CFG_STR_DIAG_RX_HEX_ID,...
                   CFG_NUM_XCP_CAN_CHANNEL_ID,...
                   CFG_STR_XCP_RESPONSE_TX_HEX_ID,...
                   CFG_STR_XCP_HEARTBEAT_TX_HEX_ID,...
                   CFG_STR_XCP_REQUEST_RX_HEX_ID,...
                   CFG_STR_XCP_HEARTBEAT_RX_HEX_ID,...
                   CFG_FLAG_GEN_LIB,...
                   CFG_STR_OUTPUT_COM_LIB_NAME,...
                   CFG_FLAG_SHOW_GEN_LIB,...
                   CFG_FLAG_SAVE_LOGS_TO_WORKSPACE,...
                   CFG_SIGNED_SIGNALS_SUPPORTED,...
                   CFG_CAN_TASK_MS);

if(strcmp(Status,'STATUS_NOK'))
    fprintf(2,['TAPAS ERROR: Configuration files have not been generated correctly, check errors above ...' '\n']);
end

if((CFG_FLAG_MOVE_FILE_TO_PROJECT == true) && (strcmp(Status,'STATUS_OK')))
    disp('Moving the generated files to the parent project configurations folder')
    projectPath = lib_get_project_path('01_Software');
    
    movefile('tapas_types_dbc.m', [projectPath '\01_Code\APP\app_types\tapas_types_dbc.m'],'f')
    movefile('ecu_com_cfg_gen.c', [projectPath '\01_Code\TAPAS\Cfg\' CFG_STR_PATH_TAPAS_CFG '\ECU\com\ecu_com_cfg_gen.c'],'f')
    movefile('ecu_com_cfg_gen.h', [projectPath '\01_Code\TAPAS\Cfg\' CFG_STR_PATH_TAPAS_CFG '\ECU\com\ecu_com_cfg_gen.h'],'f')
    movefile('ecu_com_cfg.h', [projectPath '\01_Code\TAPAS\Cfg\' CFG_STR_PATH_TAPAS_CFG '\ECU\com\ecu_com_cfg.h'],'f')
    movefile('ecu_com_cfg.c', [projectPath '\01_Code\TAPAS\Cfg\' CFG_STR_PATH_TAPAS_CFG '\ECU\com\ecu_com_cfg.c'],'f')
    movefile('ecu_txcp_cfg_gen.h', [projectPath '\01_Code\TAPAS\Cfg\' CFG_STR_PATH_TAPAS_CFG '\ECU\txcp\ecu_txcp_cfg_gen.h'],'f')
    movefile('uc_can_cfg.h', [projectPath '\01_Code\TAPAS\Cfg\' CFG_STR_PATH_TAPAS_CFG '\UC\can\uc_can_cfg.h'],'f')
    movefile('uc_can_cfg.c', [projectPath '\01_Code\TAPAS\Cfg\' CFG_STR_PATH_TAPAS_CFG '\UC\can\uc_can_cfg.c'],'f')
    
    disp('Moving the generated files to the parent project configurations folder done ..')
end

if(CFG_CLEAR_OUTPUT == true)
    disp('Clearing Outputs ...')
    clear;
    disp('Clearing Outputs Done...')
end

disp('Done ...')
