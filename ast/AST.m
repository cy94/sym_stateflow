classdef AST
    % AST: Abstract Syntax Tree for Arithmeftic / Boolean expressions
    %  The AST is built by parsing an expression
    %  Includes
    %   int, boolean
    %   arithmetic (+, -, *, /)
    %   logical (&&, ||, ~)
    %   relational (==, ~=, >, <, >=, <=)
    
    properties (GetAccess = private)
        root % root node
    end
    
    methods
        function obj = AST()
            'created AST'
        end
    end
    
end

