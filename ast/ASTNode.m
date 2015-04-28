classdef ASTNode < handle
    %ASTNODE Node of an Abstract Syntax Tree (AST)
    %    This is the parent class for all operators and 
    %    expression nodes
    %    The AST is built by parsing an expression (see parse.m)
    %    Includes
    %       variable, constant
    %       arithmetic (+, -, *, /)
    %       logical (&&, ||, ~)
    %       relational (==, ~=, >, <, >=, <=)
    %       assignment (=)
    
    properties
        % The parent node of the this node. The root of the AST
        % does not have a parent node
        parent_node
    end
    
    methods
    end
end

