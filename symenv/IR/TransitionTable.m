classdef TransitionTable
    %TRANSITIONTABLE Table of Transitions and guards/actions in them
    %   Table structure
    %   Uses containers.Map
    %         
    %   Transition from S1 -> S2
    %   map= Source State Name -> map with Destination State Names as keys
    %   Destination State Name -> 
       

    properties
    end
    
    methods
        function obj = TransitionTable()
        end
        
%         returns the transition guard / action set for the
%         transition from s1 to s2
        function obj = get(s1, s2)
        end
        
    end
    
end

