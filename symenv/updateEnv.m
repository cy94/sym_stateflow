% updateEnv.m
% 
% 
% Updates the symbolic execution environment
% with one SETBasicBlock and one SETDecisionBlock
% 
% Based on the previous Stateflow state and the current state, 
% update these blocks with the actions (entry, during, exit, 
% currently only assignment actions. eg: x = 10) and 
% constraints (eg: x < 5 && y > 10)
% 
% For each transition, update it using the previous state's 
% exit action, the transition guard and action, and the next state's
% entry action

disp('Updating symbolic environment');

prev_state = current_state;
current_state = char(new_state);

% state_name without any associated state(s)
bad_state_name = char(state_name.None);

% first transition is discarded
if(strcmp(prev_state, bad_state_name) && strcmp(current_state, bad_state_name))
    return
end

% new SET blocks
newBasicBlock = SETBasicBlock();
newDecisionBlock = SETDecisionBlock();

% add to list
SETBB_list{end + 1} = newBasicBlock;
SETDB_list{end + 1} = newDecisionBlock;

% during action - if transition is from a state to itself
if(strcmp(prev_state, current_state))
    fprintf('During: %s\n', current_state);
    
    action_ast_list = state_table.get(current_state).during_action;
    newBasicBlock.update(action_ast_list, SETBB_list);
    
    return
end

% proper transition: prev_state -> current_state 
if(~strcmp(prev_state, bad_state_name) && ~strcmp(current_state, bad_state_name))
    
    % exit action for previous state
    fprintf('Exit: %s\n', prev_state);
    action_ast_list = state_table.get(prev_state).exit_action;
    newBasicBlock.update(action_ast_list, SETBB_list);
    
    % guard/action set for the transition
    tr_set = transition_table.get(prev_state, current_state);
    
    % transition guard
    fprintf('Transition guard\n');
    guard_ast = tr_set.guard;
    newDecisionBlock.update(guard_ast, SETBB_list);
    
    % transition action
    fprintf('Transition action\n');
    action_ast_list = tr_set.action;
    newBasicBlock.update(action_ast_list, SETBB_list);
end

fprintf('Entry: %s\n', current_state);

% entry action for current_state
action_ast_list = state_table.get(current_state).entry_action;
newBasicBlock.update(action_ast_list, SETBB_list);









    
