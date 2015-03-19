classdef Variable < ASTNode
    %VARIABLE Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        name
    end
    
    methods
        function obj = Variable(name)
            obj.name = name;
        end
    end
    
end

