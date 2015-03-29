% updateEnv.m
% 
% 
% Updates the symbolic execution environment
% with SETBasicBlock and SETDecisionBlock

disp('Updating symbolic environment');

prev_state = current_state;
current_state = char(new_state);

% state_name without any associated state(s)
bad_state_name = char(state_name.None);

% first transition is discarded
if(strcmp(prev_state, bad_state_name) && strcmp(current_state, bad_state_name))
%     ends the script
    return
end

% during action - if transition is from a state to itself
if(strcmp(prev_state, current_state))
    %     update SET
    fprintf('During: %s\n', current_state);
    return
end

% proper transition: prev_state -> current_state (both not None)
if(~strcmp(prev_state, bad_state_name) && ~strcmp(current_state, bad_state_name))
    % everything except entry action for current_state:
    %     
    % exit action for previous state
    % transition guard
    % transition action
    % entry action of new state
    fprintf('Exit: %s\n', prev_state);
end

% entry action for current_state
fprintf('Entry: %s\n', current_state);




    
