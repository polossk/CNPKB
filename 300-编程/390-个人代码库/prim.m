function [mst_length, edges] = prim(cost, inf_length)
    m = length(cost);
    vis = [true; false(m - 1, 1); ]; % 标记是否访问
    src = ones(m, 1); % 记录最小生成树到 i 号点最短距离的路径来源
    dis = cost(1, :); % 记录最小生成树到 i 号点最短距离
    mst_length = 0;
    % 最小生成树的边，第 k 条边链接了 i <-> j 两点，则
    edges = zeros(m - 1, 2); % edges(k, :) = [i, j]
    for k = 1:m - 1
        min_cost = inf_length;
        p = -1;
        q = -1;
        for jj = 1:m
            if (~vis(jj) && min_cost > dis(jj))
                min_cost = dis(jj); % 记录最短路径
                p = src(jj); % 记录来源
                q = jj; % 记录去向
            end
        end
        % mst_length
        mst_length = mst_length + min_cost; % 记录总长度
        vis(q) = true; % q 点已经被访问
        edges(k, :) = [p, q]; % 记录边的端点 p <-> q
        for jj = 1:m
            if (~vis(jj) && dis(jj) > cost(jj, q))
                dis(jj) = cost(jj, q); % 更新最短路径
                src(jj) = q; % 更新来源
            end
        end
    end
end
