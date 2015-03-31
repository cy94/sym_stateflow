classdef TransitionTable
    %TRANSITIONTABLE Table of Transitions and guards/actions in them
    %   Table structure
    %   Uses containers.Map
    %         
    %   Transition from S1 -> S2
    %   map= Source State Name -> map with Destination State Names as keys
    %   Destination State Name -> 
       

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

