```mermaid
flowchart LR

subgraph Robot
    R[Robot Core]
end

subgraph Localization
    L[Localization]
    P1[Current Pose]
end

subgraph Navigation
    L[part1]
    P1[part3]
    R[part2]
end