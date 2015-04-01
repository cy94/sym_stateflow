classdef ASTNode
    %ASTNODE Node of an Abstract Syntax Tree (AST)
    %  This is the parent class for all operators and 
    %  expression nodes
    %  The AST is built by parsing an expression (see parse.m)
    %  Includes
    %   variable, constant
    %   arithmetic (+, -, *, /)
    %   logical (&&, ||, ~)
    %   relational (==, ~=, >, <, >=, <=)
    %   assignment (=)
    
    properties
        parent
    end
    
    methods
    end
end

