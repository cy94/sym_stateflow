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

% new SET blocks
newBasicBlock = SETBasicBlock();
newDecisionBlock = SETDecisionBlock();

% during action - if transition is from a state to itself
if(strcmp(prev_state, current_state))
    fprintf('During: %s\n', current_state);
    
    action_ast = state_table.get(current_state).during_action;
    newBasicBlock.update(action_ast, SETBB_list);
    
    SETBB_list{end + 1} = newBasicBlock;
    return
end

% proper transition: prev_state -> current_state (both not None)
if(~strcmp(prev_state, bad_state_name) && ~strcmp(current_state, bad_state_name))
    fprintf('Exit: %s\n', prev_state);
        
    % exit action for previous state
    action_ast = state_table.get(prev_state).exit_action;
    newBasicBlock.update(action_ast, SETBB_list);
    
    % guard/action set for the transition
    tr_set = transition_table.get(prev_state, current_state);
    
    % transition guard
    guard_ast = tr_set.guard;
    newDecisionBlock.update(guard_ast, SETBB_list);
    
    % transition action
    action_ast = tr_set.action;
    newBasicBlock.update(action_ast, SETBB_list);
    
    
end

fprintf('Entry: %s\n', current_state);

% entry action for current_state
action_ast = state_table.get(current_state).entry_action;
newBasicBlock.update(action_ast, SETBB_list);

SETBB_list{end + 1} = newBasicBlock;
SETDB_list{end + 1} = newDecisionBlock;







    
