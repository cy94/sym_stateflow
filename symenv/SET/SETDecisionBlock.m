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
        
%         creates a new path constraint with the condition in 'ast'
%         (eg: x < 10) by using all previous basic blocks stored 
%         in 'BB_list'
        function update(obj, ast, BB_list)
            
        end
    end
    
end

