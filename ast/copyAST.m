function [ newAST ] = copyAST( ast )
%COPYAST creates a deep copy of ast (ASTNode)
%   for variable and constant nodes, creates a copy with the same value
%   for all other nodes, creates a copy and recursively copies children
    
%   call the constructor of ast
    

    if(isa(ast, 'Variable'))
        newAST = feval(class(ast), []);
        newAST.name = ast.name;
        return;
    elseif(isa(ast, 'Constant')) 
        newAST = feval(class(ast), []);
        newAST.value = ast.value;
        return;
    else
        newAST = feval(class(ast), [], []);
        newAST.left_node = copyAST(ast.left_node);
        newAST.right_node = copyAST(ast.right_node);
    end
end

