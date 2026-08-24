class BrowserHistory {
    struct Page {
        string url; // curr page url
        Page* prev;
        Page* next;
        Page(): url(""), prev(nullptr), next(nullptr) {}
        Page(string _url): url(_url), prev(nullptr), next(nullptr) {}
    };
    Page* head;
    Page* curr_page;

public:
    BrowserHistory(string homepage) {
        head = new Page(homepage);
        curr_page = head;
        cout << "new homepage: " << head->url << endl;
    }
    
    void visit(string url) {
        Page* new_page = new Page(url);
        Page* forward_history = curr_page->next;
        new_page->prev = curr_page;
        curr_page->next = new_page;
        // delete the forward history after the curr page
        if(!forward_history) {
            curr_page = new_page;
            return;
        }
        while(forward_history->next) {
            // point to the tail
            forward_history = forward_history->next;
        }
        while(forward_history != curr_page) {
            Page* temp = forward_history;
            forward_history = forward_history->prev;
            delete temp;
        }
        cout << new_page->url << "=" << curr_page->url << endl;
        curr_page = new_page;
    }
    
    string back(int steps) {
        Page* page_node = curr_page->prev;
         while(page_node && steps > 0){
            cout << " back from: " << curr_page->url;
            steps--;
            curr_page = page_node;
            page_node = curr_page->prev;
        }
        return curr_page->url;
    }
    
    string forward(int steps) {
        Page* page_node = curr_page->next;
        while(page_node && steps > 0){
            steps--;
            curr_page = page_node;
            page_node = page_node->next;
        }
        return curr_page->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */