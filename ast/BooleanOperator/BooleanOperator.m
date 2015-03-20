classdef BooleanOperator < Operator
    %BOOLEANOPERATOR Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function obj = BooleanOperator(left, right)
            obj = obj@Operator(left, right)
        end
    end
    
end

