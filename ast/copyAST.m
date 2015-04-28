function [ newAST ] = copyAST( ast )
%COPYAST returns a deep copy of ast (ASTNode)
%   for variable and constant (leaf) nodes, creates a copy with the 
%   same value and for all other nodes, creates a copy and 
%   recursively copies child nodes
    
    if(isa(ast, 'Variable'))
        newAST = feval(class(ast), ast.name);
%         newAST.name = ast.name;
        return;
    elseif(isa(ast, 'Constant')) 
        newAST = feval(class(ast), ast.value);
%         newAST.value = ast.value;
        return;
    else
        newAST = feval(class(ast), ...
            copyAST(ast.left_node), ...
            copyAST(ast.right_node));
    end
end

