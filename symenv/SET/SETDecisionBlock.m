classdef SETDecisionBlock
    %SETDECISIONBLOCK Stores the path constraint during symbolic execution
    %   Stores a single AST (boolean) node for the transition guard
    %   during symbolic execution
    
    properties
        ast
    end
    
    methods
        function set(obj, ast)
            obj.ast = ast;
        end
        
        function ast = get(obj)
            ast = obj.ast;
        end
    end
    
end

