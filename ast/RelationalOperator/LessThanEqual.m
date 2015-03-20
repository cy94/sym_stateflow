classdef LessThanEqual < RelationalOperator
    %LESSTHANEQUAL Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function obj = LessThanEqual(left, right)
            obj = obj@RelationalOperator(left, right)
        end
    end
    
end

