% initEnv.m
% 
% Initializes the symbolic environment for the currently opened 
% Stateflow chart. Parses entry / during / exit actions for states
% and guards / transition actions for transitions and stores the AST
% (Abstract Syntax Tree) for each

% clear the workspace - using base workspace for all variables
clc
clear all

disp('Initializing symbolic environment');

% add listener to model, used to update the sym env
update_listener = add_exec_event_listener('simple/Simple Chart', 'PreOutputs', @updateEnvCallback);

% store the simulink root
root = sfroot();

% and chart
chart = root.find('-isa', 'Stateflow.Chart');

fprintf('Opened chart: %s\n', chart.Name);

% get states and transitions
states = chart.find('-isa', 'Stateflow.State');
transitions = chart.find('-isa', 'Stateflow.Transition');

% parse state labels and add to table
disp('States');
statelabel_expr = '(?<name>.*)?\nen:(?<entry>.*)\ndu:(?<during>.*)\nex:(?<exit>.*)';

% create table of action -> ASTs
state_table = StateActionTable();

for i = 1 : length(states)
    fprintf('---------\n');
    disp(states(i).LabelString);
    out = regexp(states(i).LabelString, statelabel_expr, 'names');
    disp(out);
    fprintf('---------\n');
    
    action_set = StateActionSet();
    
    % for entry, during, exit
    %     split on ';' and strtrim
    %     remove empty tokens
    %     get AST for each line and add to action_set
    % TODO: refactor this
%%%%%%%%%%%%%%    
    lines = strtrim(strsplit(out.entry, ';'));
    lines(strcmp('', lines)) = [];
    
    for j = 1 : numel(lines)
        ast = parse(lines{j});
        action_set.add_entry_action(ast);
    end
%%%%%%%%%%%%%%
    lines = strtrim(strsplit(out.during, ';'));
    lines(strcmp('', lines)) = [];
    
    for j = 1 : numel(lines)
        ast = parse(lines{j});
        action_set.add_during_action(ast);
    end
%%%%%%%%%%%%%%
    lines = strtrim(strsplit(out.exit, ';'));
    lines(strcmp('', lines)) = [];
    
    for j = 1 : numel(lines)
        ast = parse(lines{j});
        action_set.add_exit_action(ast);
    end
%%%%%%%%%%%%%%

%     add action set to table
    state_table.add(out.name, action_set);
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% parse transition labels and add to table
disp('Transitions');
translabel_expr = '\[(?<guard>.*)\]/\{(?<action>.*)\}';
transition_table = MapN();

for i = 1 : length(transitions)
%   skip the initial / default transition - doesnt have a source
    if(~isempty(transitions(i).Source))
        fprintf('%s', transitions(i).Source.Name);
    
        fprintf('->%s: %s\n', transitions(i).Destination.Name, transitions(i).LabelString);
        fprintf('---------\n');
        
        out = regexp(transitions(i).LabelString, translabel_expr, 'names');
        disp(out);
        
        %     store ASTs in struct
        ast = parse(out.guard);
        tr_set.guard = ast;
        
        ast = parse(out.action);
        tr_set.action = ast;
        
        %    store struct in MapN (misc/MapN)
        transition_table(transitions(i).Source.Name, transitions(i).Destination.Name) = tr_set;
    end
end

% variable to store the current state - used in updateEnv
% state_name is an enum created by Statefow Active State Output 
current_state = char(state_name.None);
prev_state = char(state_name.None);
new_state = char(state_name.None);

% create empty SETBB and SETDB lists
SETBB_list = {};
SETDB_list = {};

fprintf('Finished initEnv\n----------------\n');