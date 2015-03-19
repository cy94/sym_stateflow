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

% parse state labels and add to table
% (see tests/regex.m)
disp('States');
statelabel_expr = '(?<name>.*)?\nen:(?<entry>.*)\ndu:(?<during>.*)\nex:(?<exit>.*)';

for i = 1 : length(states)
    disp(states(i).LabelString);
    out = regexp(states(i).LabelString, statelabel_expr, 'names');
    disp(out);
    fprintf('---------\n');
end

% parse transition labels and add to table
disp('Transitions');
translabel_expr = '\[(?<guard>.*)\]/\{(?<action>.*)\}';

for i = 1 : length(transitions)
%   the initial / default transition doesnt have a source
    if(size(transitions(i).Source) ~= 0)
        fprintf('%s', transitions(i).Source.Name);
    end
    
    fprintf('->%s: %s\n', transitions(i).Destination.Name, transitions(i).LabelString);
    fprintf('---------\n');
    
    out = regexp(transitions(i).LabelString, translabel_expr, 'names');
    disp(out);
end

% create parsed state/transition + AST table


