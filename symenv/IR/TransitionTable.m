classdef TransitionTable
    %TRANSITIONTABLE Map of: Transitions -> guards/actions 
    %   Uses external library MapN
    %         
    % Structure: 
    %   Transition from S1 -> S2
    %   map(S1, S2) = struct 
    %   where struct.guard   = guard AST  
    %   and   struct.actions = list of action ASTs
       

    properties
        map
    end
    
    methods
        function obj = TransitionTable()
            obj.map = MapN();
        end
        
%         set the guard/action structure for the transition
%         from s1 -> s2
        function set(obj, s1, s2, tr_set)
            obj.map(s1, s2) = tr_set;
        end
        
%         returns the transition guard/action structure for the
%         transition from s1 -> s2
        function tr_set = get(obj, s1, s2)
            tr_set =  obj.map(s1, s2);
        end
        
    end
    
end

