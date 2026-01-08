int EditDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();

    // dp[i][j] = costo para convertir los primeros 'i' chars de word1
    // en los primeros 'j' chars de word2.
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Casos base: Llenar la primera fila y columna
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i; // Costo de 'i' eliminaciones
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j; // Costo de 'j' inserciones
    }

    // Llenar el resto de la tabla
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // Se usa i-1 y j-1 porque los strings son 0-indexados
            if (word1[i - 1] == word2[j - 1]) {
                // Si los caracteres coinciden, no hay costo adicional
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Costo de 1 + el mínimo de las 3 operaciones
                dp[i][j] = 1 + min({dp[i - 1][j - 1],  // Reemplazar
                                   dp[i - 1][j],      // Eliminar
                                   dp[i][j - 1]});    // Insertar
            }
        }
    }

    // La respuesta final está en la esquina inferior derecha
    return dp[n][m];
}
