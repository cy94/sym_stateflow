classdef Or < BooleanOperator
    %OR Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function obj = Or(left, right)
            obj = obj@BooleanOperator(left, right)
        end
    end
    
end

