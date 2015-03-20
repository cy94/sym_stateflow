classdef RelationalOperator < Operator
    %RELATIONALOPERATOR Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function obj = RelationalOperator(left, right)
            obj = obj@Operator(left, right)
        end
    end
    
end

