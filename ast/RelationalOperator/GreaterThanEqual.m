classdef GreaterThanEqual < RelationalOperator
    %GREATERTHANEQUAL Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function obj = GreaterThanEqual(left, right)
            obj = obj@RelationalOperator(left, right)
        end
    end
    
end

