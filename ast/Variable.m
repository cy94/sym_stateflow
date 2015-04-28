classdef Variable < ASTNode
    %VARIABLE Variable ASTNode
    %   Represents a MATLAB variable
    %   The node stores only the name of the variable 
    %   as a string
    
    properties
    % name of the variable
        name
    end
    
    methods
        function obj = Variable(name)
            obj.name = name;
        end
    end
    
end

