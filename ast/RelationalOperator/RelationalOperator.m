classdef RelationalOperator < Operator
    %RELATIONALOPERATOR Base class for relational operators
    %   Eg: <, >, <= ...
    
    properties
    end
    
    methods
        function obj = RelationalOperator(left, right)
            obj = obj@Operator(left, right)
        end
    end
    
end

