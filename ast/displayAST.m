function displayAST( ast )
%DISPLAYAST displays the nodes of an AST
%   uses Breadth First Search (BFS)

	queue = { ast };

	while(~isempty(queue))
		node = queue{1}; queue = queue(2:end);

		classname = class(node);

		fprintf('%s', classname);

		if (isa(node, 'Variable'))
			fprintf(': %s', node.name);
		elseif (isa(node, 'Constant'))
			fprintf(': %s', num2str(node.value));
		else
			queue = [ queue,  ... 
                     {node.left_node, ...
                      node.right_node} ];
		end

		fprintf('\n');
	end
end

