classdef StateActionTable
    %STATEACTIONTABLE Table of States and actions in them
    %   Table structure
%      ---------------------------------------------
%     | State name (string) | StateActionSet object |
%      ---------------------------------------------
%     Uses containers.Map

    properties
        map
    end
    
    methods
        function obj = StateActionTable()
            obj.map = containers.Map();
        end
        
        function add(obj, state_name, state_action_set)
            obj.map(state_name) = state_action_set;
        end
        
        function action_set = get(obj, state_name)
            if(obj.map.isKey(state_name))
                action_set = obj.map(state_name);
            else
                action_set = [];
            end
        end
    end
    
end

