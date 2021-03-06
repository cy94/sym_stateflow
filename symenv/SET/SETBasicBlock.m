    classdef SETBasicBlock < handle
    
    %SETBASICBLOCK Variable -> AST Mappings in the SET
    %   SET = Symbolic Execution Trace
     
    %   Used to store mappings of variables to current values
    %   during symbolic execution
    %   Uses a containers.Map object with
    %         key   = Variable Name (string)
    %         value = AST node (ASTNode) value for that variable
    
    properties
        map
    end
    
    methods
        function obj = SETBasicBlock()
            obj.map = containers.Map();
        end
         
%         variable: name of the variable (string)
%         AST: AST expression for value of variable
        function set(obj, varname, AST)
            obj.map(varname) = AST;
        end
        
%         get the AST expression value for a variable name
        function AST = get(obj, varname)
            if(obj.map.isKey(varname))
                AST = obj.map(varname);
            else
                AST = [];
            end
        end
        
%         updates the map of variables in 'obj' with the actions in
%         'ast_list' (eg: x = x + 1) by using the previous basic 
%         blocks in 'BB_list'
%          
%         performs a Breadth First Search on the new assignment AST
%         and replaces variables with previous AST values 
        % eg: previous value is x = 5 with the AST
        %       =
        %     /   \
        %    x     1
        %   and the new assignment is x = x + 1
        %         =
        %        / \
        %       x   +
        %          / \
        %         x   1
        % The x on the right side of the equation is replaced by its 
        % previous value of 5
        %         =
        %        / \
        %       x   +
        %          / \
        %         5   1


        function update(obj, ast_list, BB_list)
            for i = 1:numel(ast_list)
                
                ast = ast_list{i};

    %           ast is an assignment
                if(isa(ast, 'Assignment'))
                    var_name = ast.left_node.name;
                    new_value_ast = copyAST(ast.right_node);

    %               find latest value of 'Variable's in new_value_ast
    %               do a Breadth First Search on the tree to find the 
    %               Variable nodes

    %               add root to queue
                    queue = { new_value_ast };

                    while(~isempty(queue))
                        node = queue{1}; queue = queue(2:end);

                        if(isa(node, 'Variable'))
    %                       lookup previous value of 'node' 
                            node_var_name = node.name;
                            
                            for j = numel(BB_list): -1 : 1
                                basic_block = BB_list{j};
                                old_var_ast = basic_block.get(node_var_name);

                                if(~isempty(old_var_ast))
    %                               found the previous value
    %                               make a copy of the ast
                                    copy_var_ast = copyAST(old_var_ast);

    %                               add to new_value_ast


                                    if(isempty(node.parent_node))
    %                               no parent - this is the only node in 
    %                               new_value_ast
                                        new_value_ast = copy_var_ast;
                                    elseif(node == node.parent_node.left_node)    
                                        node.parent_node.left_node = copy_var_ast;
                                        copy_var_ast.parent_node = node.parent_node;
                                    else
                                        node.parent_node.right_node = copy_var_ast;
                                        copy_var_ast.parent_node = node.parent_node;
                                    end

                                    break
                                end

                            end

                        elseif(~isa(node, 'Constant')) 
    %                       add children to queue
                            queue = [ queue,  ... 
                                     {node.left_node, ...
                                      node.right_node} ];
                        end
                    end

    %               update the basic block
                    obj.set(var_name, new_value_ast);
                end
            end
        end
        
    end
    
end

