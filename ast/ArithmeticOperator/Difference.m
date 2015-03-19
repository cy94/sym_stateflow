 classdef Difference < ArithmeticOperator
    %DIFFERENCE Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function obj = Difference(left, right)
            obj = obj@ArithmeticOperator(left, right);
        end
    end
    
end

