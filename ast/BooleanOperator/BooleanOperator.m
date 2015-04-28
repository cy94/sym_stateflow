classdef BooleanOperator < Operator
    %BOOLEANOPERATOR Base class for boolean operators
    %   Eg: and (&&), or (||)
    
    properties
    end
    
    methods
        function obj = BooleanOperator(left, right)
            obj = obj@Operator(left, right)
        end
    end
    
end

