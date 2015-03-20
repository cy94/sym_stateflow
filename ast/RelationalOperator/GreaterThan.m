classdef GreaterThan < RelationalOperator
    %GREATERTHAN Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function obj = GreaterThan(left, right)
            obj = obj@RelationalOperator(left, right)
        end
    end
    
end

