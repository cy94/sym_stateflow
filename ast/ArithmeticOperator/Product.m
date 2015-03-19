classdef Product < ArithmeticOperator
    %PRODUCT Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function obj = Product(left, right)
            obj = obj@ArithmeticOperator(left, right);
        end
    end
    
end

