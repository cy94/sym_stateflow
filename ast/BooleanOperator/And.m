classdef And < BooleanOperator
    %AND Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function obj = And(left, right)
            obj = obj@BooleanOperator(left, right)
        end
    end
    
end

