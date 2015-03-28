function callbackFunc( block, data )
%CALLBACKFUNC a callback function for stateflow PostOutputs Event
% Runs script that updates the symbolic environment 
% Needs to be run in the base environment as data created in
% initEnv (init script for environment) needs to be used by updateEnv
    evalin('base', 'updateEnv'); 
end

