classdef Constant < ASTNode
    %CONSTANT Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        value
    end
    
    methods
        function obj = Constant(value)
            fprintf('New constant node: %d\n', value);
            obj.value = value;
        end
    end
    
end

