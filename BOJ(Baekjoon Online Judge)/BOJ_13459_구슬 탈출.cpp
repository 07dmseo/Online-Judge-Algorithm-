
void move(int &x, int &y, int &c, int dx, int dy) {
    while (a[x+dx][y+dy] != '#' && a[x][y] != 'O') {
        x += dx;
        y += dy;
        c += 1;
    }
}

void bfs() {
    while (!q.empty()) {
        int rx = q.front().rx, ry = q.front().ry;
        int bx = q.front().bx, by = q.front().by;
        int d = q.front().d; q.pop();
        if (d >= 10) break;
        for (int i=0; i<4; i++) {
            int nrx = rx, nry = ry, nbx = bx, nby = by;
            int rc = 0, bc = 0;
            move(nrx, nry, rc, dx[i], dy[i]); // Moving red bead.
            move(nbx, nby, bc, dx[i], dy[i]); // Moving blue bead.
            if (a[nbx][nby] == 'O') continue; // Blue bead cannot fall into hole.
            if (a[nrx][nry] == 'O') {   // Red bead falls into hole.
                printf("1\n");
                return;
            }
            if (nrx == nbx && nry == nby) { // Beads cannot be placed in the same position.
                if (rc > bc) nrx -= dx[i], nry -= dy[i]; // Go back to previous.
                else nbx -= dx[i], nby -= dy[i];
            }
            if (check[nrx][nry][nbx][nby]) continue; // Already visited.
            check[nrx][nry][nbx][nby] = true;
            q.push({nrx, nry, nbx, nby, d+1});
        }
    }
    printf("0\n");
}

int main() {
    scanf("%d %d", &n, &m);
    int rx = 0, ry = 0, bx = 0, by = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1s", &a[i][j]);
            if (a[i][j] == 'R') rx = i, ry = j;
            else if (a[i][j] == 'B') bx = i, by = j;
        }
    }
    q.push({rx, ry, bx, by, 0});
    check[rx][ry][bx][by] = true;
    bfs();
    return 0;
}