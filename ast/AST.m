classdef AST
    % AST: Abstract Syntax Tree for Arithmetic / Boolean expressions
    %  The AST is built by parsing an expression
    %  Includes
    %   int, boolean
    %   arithmetic (+, -, *, /)
    %   logical (&&, ||, ~)
    %   relational (==, ~=, >, <, >=, <=)
    %   assignment (=)
    
    properties (GetAccess = private)
        root % root node
    end
    
    methods
        function obj = AST()
        end
    end
    
end

