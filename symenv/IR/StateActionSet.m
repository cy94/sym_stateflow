classdef StateActionSet < handle
    %STATEACTIONSET set of en, du, ex actions in a state
    %   Each action is a set of ASTs 
    %   The set is stored as a cell array
    
    properties
        entry_action 
        during_action
        exit_action
    end
    
    methods
        function obj = StateActionSet()
            obj.entry_action = {};
            obj.during_action = {};
            obj.exit_action = {};
        end
        
        function add_entry_action(obj, ast)
            obj.entry_action{end + 1} = ast;
        end
        
        function add_during_action(obj, ast)
            obj.during_action{end + 1} = ast;
        end
        
        function add_exit_action(obj, ast)
            obj.exit_action{end + 1} = ast;
        end
        
    end
end

