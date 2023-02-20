function plot_mst(edges, points, fermats, heading)
    figure();
    red_rgb = [228, 26, 28] / 255;
    blue_rgb = [55, 126, 184] / 255;
    orange_rgb = [255, 127, 0] / 255;
    green_rgb = [77, 175, 74] / 255;
    n_points = length(points);
    n_fermats = length(fermats);
    if (n_fermats > 0 && n_fermats <= n_points)
        offset = n_points - n_fermats;
        for k = 1:length(edges)
            if any(edges(k, :) > offset)
                plot(points(edges(k, :), 1), points(edges(k, :), 2), ...
                    'Color', green_rgb, 'LineWidth', 1.25, 'LineStyle', '-');
            else
                plot(points(edges(k, :), 1), points(edges(k, :), 2), ...
                    'Color', blue_rgb, 'LineWidth', 1.25, 'LineStyle', '-');
            end
            hold on;
        end
    else
        for k = 1:length(edges)
            plot(points(edges(k, :), 1), points(edges(k, :), 2), ...
                'Color', blue_rgb, 'LineWidth', 1.25, 'LineStyle', '-');
            hold on;
        end
    end
    scatter(points(:, 1), points(:, 2), 40, red_rgb, 'o', 'filled');
    if (n_fermats > 0)
        hold on;
        scatter(fermats(:, 1), fermats(:, 2), 40, orange_rgb, 'o', 'filled');
    end
    title(heading);
end
