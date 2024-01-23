#include <WiFi.h>
#include <libpq-fe.h>


// Wi-Fi 相關設置
const char *ssid = "Eprotocol";
const char *password = "53734312";

// PostgreSQL 相關設置
const char *host = "192.168.50.201";
const char *user = "postgres";
const char *password_db = "admin";
const char *dbname = "data";

void setup() {
  Serial.begin(115200);
  
  // 連接到 Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  
  // 初始化 libpq
  PGconn *conn = PQsetdbLogin(host, "5432", NULL, NULL, dbname, user, password_db);
  if (PQstatus(conn) == CONNECTION_BAD) {
    Serial.println("Connection to database failed");
    Serial.println(PQerrorMessage(conn));
  } else {
    Serial.println("Connected to database");
    
    // 插入數據
    const char *query = "INSERT INTO data.TEST (angle, illumination, time) VALUES ('45', '100', NOW())";
    PGresult *res = PQexec(conn, query);
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
      Serial.println("Query failed");
      Serial.println(PQresultErrorMessage(res));
    } else {
      Serial.println("Query successful");
    }
    
    // 關閉連接
    PQfinish(conn);
  }
}

void loop() {
  // 主循環中不需要執行任何操作
}
