classdef LessThan < RelationalOperator
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function obj = LessThan(left, right)
            obj = obj@RelationalOperator(left, right)
        end
    end
    
end

