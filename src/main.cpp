#include <iostream>
#include <randomx.h>
#include <uv.h>
#include <rapidjson/writer.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/document.h>

constexpr char* poolHost = "gulf.moneroocean.stream"
constexpr int poolPort = 10032
constexpr char address = "44PzNdHAcKu3kMpK2R15HqXdf1Zf77wpr1ookej5WaT4HnfuseBXMsP4Qfu9ysuSUuR6cdxSMHTj7E9q3bYWUeDQ1ovt5Ap"
constexpr char* name = "XMRMiner" + &'X'


enum ConnectionStatus
{
    Disconnection,
    Connecting,
    Connected
};
ConnectionStatus connectionStatus = ConnectionStatus::Disconnection;
//pool var

randomx_cache* cache = nullptr;
randomx_vm* vm = nullptr;
// randomx var

uv_loop_t* loop = nullptr;
uv_tcp_t* socket;
uv_connection_t connectRequest;
uv_stream_t serverStream = nullptr;
//uv var

void asyncCallback(uv_async_t* handle) {

}

void connectCallback()

void readCallback(uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf) {
    if (nread < 0) {
        if (nread == UV__EOF) std::count << "Pool connection stop" << std::endl;
        else std::cerr << "Read data error" << uv_strerror(nread) << std::endl;
        uv_close(reinterpret_cast<uv_handle_t*>(stream), nullptr);
        connectionStatus = ConnectionStatus::Disconnected;
    }
    else if (nread > 0) {
        std::string receivedData(buf->base, nread);
        rap
    }
}

void mainInit() {
    loop = uv_default_loop();
    uv_tcp_init(loop, &socket);
    sockaddr_in dest;
    uv_ip4_addr(poolHost, poolPort, &dest);
    uv_tcp_connect(&connectRequest, &socket, reinterpret_cast<const sockaddr*>(&dest), connectCallback);
    uv_read_start(serverStream, [](uv_handle_t*, size_t suggested_size, uv_buf_t* buf) {
        buf->base = new char[suggested_size];
        buf->len = suggested_size;
        }, readCallback)
}

int main() {
    mainInit()
}