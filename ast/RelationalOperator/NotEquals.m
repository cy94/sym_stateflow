classdef NotEquals < RelationalOperator
    %NOTEQUALS Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function obj = NotEquals(left, right)
            obj = obj@RelationalOperator(left, right)
        end
    end
    
end

