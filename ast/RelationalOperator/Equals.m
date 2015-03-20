classdef Equals < RelationalOperator
    %EQUAL Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function obj = Equals(left, right)
            obj = obj@RelationalOperator(left, right)
        end
    end
    
end

