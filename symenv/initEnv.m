% initEnv.m
% 
% Initializes the symbolic environment for the currently opened 
% Stateflow chart. Parses entry / during / exit actions for states
% and guards / transition actions for transitions and stores the AST
% (Abstract Syntax Tree) for each


disp('initializing symbolic environment');
% count number of transitions
num_trans = 0;

% store the simulink root
root = sfroot();

% and chart
chart = root.find('-isa', 'Stateflow.Chart');	
fprintf('Opened chart: %s\n', chart.Name);

% get states and transitions
states = chart.find('-isa', 'Stateflow.State');
transitions = chart.find('-isa', 'Stateflow.Transition');

disp('States');
for i = 1 : length(states)
    disp(states(i).LabelString);
    fprintf('---------\n');
end

disp('Transitions');
for i = 1 : length(transitions)
%   the initial / default transition doesnt have a source
    if(size(transitions(i).Source) ~= 0)
        fprintf('%s', transitions(i).Source.Name);
    end
    
    fprintf('-> %s: %s\n', transitions(i).Destination.Name, transitions(i).LabelString);
    fprintf('---------\n');
end

% create parsed state/transition + AST table


